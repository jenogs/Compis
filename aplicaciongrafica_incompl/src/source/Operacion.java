package source;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;
import java.awt.SystemColor;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JTextField;
import javax.swing.JButton;

public class Operacion extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;
	private JButton btnNewButton;
	private JTextArea txtrModificarlaEjemplo;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Operacion frame = new Operacion();
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
	public Operacion() {
		setTitle("Operacion");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 230, 273);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JTextArea txtrLaVariable = new JTextArea();
		txtrLaVariable.setText("La variable:");
		txtrLaVariable.setForeground(Color.BLACK);
		txtrLaVariable.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrLaVariable.setEditable(false);
		txtrLaVariable.setColumns(10);
		txtrLaVariable.setBackground(SystemColor.menu);
		txtrLaVariable.setBounds(16, 11, 164, 20);
		contentPane.add(txtrLaVariable);
		
		textField = new JTextField();
		textField.setColumns(10);
		textField.setBounds(16, 33, 126, 20);
		contentPane.add(textField);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(16, 163, 164, 23);
		contentPane.add(textField_1);
		
		btnNewButton = new JButton("Terminar");
		btnNewButton.setBounds(53, 207, 89, 23);
		contentPane.add(btnNewButton);
		
		txtrModificarlaEjemplo = new JTextArea();
		txtrModificarlaEjemplo.setText("Modificarla\r\nEjemplo:\r\n+ 5\r\n- 2\r\nvar + 1");
		txtrModificarlaEjemplo.setForeground(Color.BLACK);
		txtrModificarlaEjemplo.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrModificarlaEjemplo.setEditable(false);
		txtrModificarlaEjemplo.setColumns(10);
		txtrModificarlaEjemplo.setBackground(SystemColor.menu);
		txtrModificarlaEjemplo.setBounds(16, 67, 164, 85);
		contentPane.add(txtrModificarlaEjemplo);
	}
}
