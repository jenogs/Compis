package source;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextArea;
import java.awt.SystemColor;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JEditorPane;
import javax.swing.JTextField;
import javax.swing.JCheckBox;
import javax.swing.JButton;

public class lectura extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					lectura frame = new lectura();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public lectura() {
		setTitle("lectura");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 250, 290);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JTextArea txtrTextoAImprimir = new JTextArea();
		txtrTextoAImprimir.setText("Pregunte por el valor:");
		txtrTextoAImprimir.setForeground(Color.BLACK);
		txtrTextoAImprimir.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrTextoAImprimir.setEditable(false);
		txtrTextoAImprimir.setColumns(10);
		txtrTextoAImprimir.setBackground(SystemColor.menu);
		txtrTextoAImprimir.setBounds(10, 11, 105, 20);
		contentPane.add(txtrTextoAImprimir);
		
		textField = new JTextField();
		textField.setBounds(10, 70, 189, 71);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JButton btnTerminar = new JButton("Terminar");
		btnTerminar.setBounds(67, 218, 89, 23);
		contentPane.add(btnTerminar);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(10, 175, 189, 32);
		contentPane.add(textField_1);
		
		JTextArea textArea = new JTextArea();
		textArea.setText("Ejemplo:\r\nTexto:  \"Da valor de x:\"");
		textArea.setForeground(Color.BLACK);
		textArea.setFont(new Font("Tahoma", Font.PLAIN, 11));
		textArea.setEditable(false);
		textArea.setColumns(10);
		textArea.setBackground(SystemColor.menu);
		textArea.setBounds(10, 37, 159, 32);
		contentPane.add(textArea);
		
		JTextArea txtrVariableDondeSe = new JTextArea();
		txtrVariableDondeSe.setText("Variable donde se guardara el valor:");
		txtrVariableDondeSe.setForeground(Color.BLACK);
		txtrVariableDondeSe.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrVariableDondeSe.setEditable(false);
		txtrVariableDondeSe.setColumns(10);
		txtrVariableDondeSe.setBackground(SystemColor.menu);
		txtrVariableDondeSe.setBounds(10, 149, 189, 20);
		contentPane.add(txtrVariableDondeSe);
	}
}
