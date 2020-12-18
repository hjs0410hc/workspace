package source;

import javax.swing.*;
import java.awt.BorderLayout;

public class simpleSwingProgram extends JFrame{
	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	BorderLayout layout = new BorderLayout();
	JButton button = new JButton("access");
	JLabel label = new JLabel("hello this is label");
	JButton button2 = new JButton("close");
	simpleSwingProgram() {
		button.addActionListener(e->{
			JOptionPane.showMessageDialog(this,"HELLO","TITLE", JOptionPane.INFORMATION_MESSAGE);
		});
		button2.addActionListener(e->{
			dispose();
		});
		setLayout(layout);
		add(button,"Center");
		add(label,"North");
		add(button2,"South");
		setTitle("Swing in VSCODE");
		setSize(300,300);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setVisible(true);
	}
	public static void main(String[] args){
		new simpleSwingProgram();
	}
}