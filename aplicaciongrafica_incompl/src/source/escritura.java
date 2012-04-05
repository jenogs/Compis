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

public class escritura extends JFrame {

	private JPanel contentPane;
	private JTextField textField;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					escritura frame = new escritura();
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
	public escritura() {
		setTitle("Escritura");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 210, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JTextArea txtrTextoAImprimir = new JTextArea();
		txtrTextoAImprimir.setText("Texto a imprimir:");
		txtrTextoAImprimir.setForeground(Color.BLACK);
		txtrTextoAImprimir.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrTextoAImprimir.setEditable(false);
		txtrTextoAImprimir.setColumns(10);
		txtrTextoAImprimir.setBackground(SystemColor.menu);
		txtrTextoAImprimir.setBounds(10, 11, 105, 20);
		contentPane.add(txtrTextoAImprimir);
		
		JTextArea txtrEjemploTextohola = new JTextArea();
		txtrEjemploTextohola.setText("Ejemplo:\r\nTexto:  \"hola\"\r\nVariable:  x\r\nMezcla:  \"hola\" + x");
		txtrEjemploTextohola.setForeground(Color.BLACK);
		txtrEjemploTextohola.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrEjemploTextohola.setEditable(false);
		txtrEjemploTextohola.setColumns(10);
		txtrEjemploTextohola.setBackground(SystemColor.menu);
		txtrEjemploTextohola.setBounds(10, 42, 105, 60);
		contentPane.add(txtrEjemploTextohola);
		
		textField = new JTextField();
		textField.setBounds(10, 113, 159, 81);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JCheckBox chckbxNewCheckBox = new JCheckBox("Cambio de linea");
		chckbxNewCheckBox.setBounds(38, 201, 105, 23);
		contentPane.add(chckbxNewCheckBox);
		
		JButton btnTerminar = new JButton("Terminar");
		btnTerminar.setBounds(48, 231, 89, 23);
		contentPane.add(btnTerminar);
	}
}
