#include <bits/stdc++.h>
using namespace std;

int remPic = 0;
int remDir = 0;/* 
class Picture{
    public:
    string picName;
    Picture(string _n) : picName{_n}{

    }
    ~Picture(){
        remPic += 1;
    }
}; */

class Album{
    public:
    string albName;
    Album* parentDir;
    // map은 자동정렬 기능이 있다. iterator를 사용하자.
    map<string,Album*> subDir;
    map<string,bool> pics;
    
    Album(string _n) : albName{_n}{

    }
    ~Album(){
        for_each(subDir.begin(),subDir.end(),[](auto& ap) { // 재귀적으로 작용할거라고 믿음
            delete ap.second;
        });
        subDir.clear();
        remPic+=pics.size();
        pics.clear();
        remDir+=1;
    }
    bool isExistDir(string name){
        if(subDir.count(name) != 0){
            return true;
        }else{
            return false;
        }
    }
    bool isExistPic(string name){
        if(pics.count(name) != 0){
            return true;
        }else{
            return false;
        }
    }
};

Album* rootDir;
Album* curDir;
int n;
string s;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    rootDir = new Album("album"); // this must not be deleted!
    curDir = rootDir;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="mkalb"){
            cin >> s;
            if(!(curDir->isExistDir(s))){ // 해당 폴더가 존재하지 않으면
                curDir->subDir[s] = new Album(s);
                curDir->subDir[s]->parentDir = curDir;
            }else{
                cout << "duplicated album name\n";
            }
        }else if(s=="rmalb"){ // most important , removing subdirectories.
            cin >> s;
            if(!(curDir->subDir.empty())){
                if(s=="-1"){ //사전순으로 가장 빠른 앨범을 삭제
                    delete (*(curDir->subDir.begin())).second;
                    curDir->subDir.erase(curDir->subDir.begin());
                }else if(s=="0"){//현재 있는 앨범의 모든 앨범을 삭제(remove all subdirectories)
                    for_each(curDir->subDir.begin(),curDir->subDir.end(),[](auto& ap){
                        delete ap.second;
                    });
                    curDir->subDir.clear();
                }else if(s=="1"){ // 사전순으로 가장 느린 앨범을 삭제
                    delete (*(--(curDir->subDir.end()))).second;
                    curDir->subDir.erase(--(curDir->subDir.end()));
                }else{
                    if(curDir->isExistDir(s)){
                        delete curDir->subDir[s];
                        curDir->subDir.erase(s);
                    }
                }
            }
            cout << remDir << " " << remPic << "\n";
            remPic =0;remDir=0;
        }else if(s=="insert"){
            cin >> s;
            if(!(curDir->isExistPic(s))){
                curDir->pics[s] = true;
            }else{
                cout << "duplicated photo name\n";
            }
        }else if(s=="delete"){ // 사진 삭제 후 삭제된 사진 개수 출력!!
            cin >> s;
            if(!(curDir->pics.empty())){
                if(s=="-1"){ // 사전순빠른 사진 삭제
                    curDir->pics.erase(curDir->pics.begin());
                    cout << 1 << "\n";
                }else if(s=="0"){
                    cout << curDir->pics.size() << "\n";
                    curDir->pics.clear();
                }else if(s=="1"){
                    curDir->pics.erase(--(curDir->pics.end()));
                    cout << 1 << "\n";
                }else{
                    if(curDir->isExistPic(s)){
                        curDir->pics.erase(s);
                        cout << 1 << "\n";
                    }else{
                        cout << 0 << "\n";
                    }
                }
            }else{
                cout << 0 << "\n";
            }
            
        }else if(s=="ca"){
            cin >> s;
            if(s==".."){
                if(curDir->parentDir != NULL){ // root에서 상위디렉터리로 가는것을 방지...
                    curDir = curDir->parentDir;
                }
            }else if(s=="/"){
                curDir = rootDir;
            }else{
                if(curDir->isExistDir(s)){
                    curDir = curDir->subDir[s];
                }
            }
            cout << curDir->albName << "\n";
        }
    }
    
    
}