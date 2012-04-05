package source;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JMenuBar;
import javax.swing.JTextField;
import java.awt.Button;
import java.awt.TextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JTextArea;
import java.awt.SystemColor;
import java.awt.Font;
import java.awt.Color;

public class condicion extends JFrame {

	private JPanel contentPane;
	private JTextArea txtrVariable;
	private JTextArea txtrOperador;
	private JTextArea txtrVariable_1;
	private JTextArea txtrProporcioneLosValores;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					condicion frame = new condicion();
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
	public condicion() {
		setTitle("Condicion (IF)");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 255, 260);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		Button button = new Button("Terminar");
		button.setBounds(83, 194, 70, 22);
		contentPane.add(button);
		
		TextField textField_3 = new TextField();
		textField_3.setBounds(83, 55, 86, 22);
		contentPane.add(textField_3);
		
		TextField textField = new TextField();
		textField.setBounds(83, 128, 86, 22);
		contentPane.add(textField);
		
		JComboBox comboBox = new JComboBox();
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"", ">", "<", "==", ">=", "<=", "&&", "||"}));
		comboBox.setToolTipText("");
		comboBox.setBounds(83, 91, 86, 20);
		contentPane.add(comboBox);
		
		txtrVariable = new JTextArea();
		txtrVariable.setText("Variable 1:");
		txtrVariable.setForeground(Color.BLACK);
		txtrVariable.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrVariable.setEditable(false);
		txtrVariable.setColumns(10);
		txtrVariable.setBackground(SystemColor.menu);
		txtrVariable.setBounds(10, 57, 70, 20);
		contentPane.add(txtrVariable);
		
		txtrOperador = new JTextArea();
		txtrOperador.setText("operador");
		txtrOperador.setForeground(Color.BLACK);
		txtrOperador.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrOperador.setEditable(false);
		txtrOperador.setColumns(10);
		txtrOperador.setBackground(SystemColor.menu);
		txtrOperador.setBounds(10, 93, 70, 20);
		contentPane.add(txtrOperador);
		
		txtrVariable_1 = new JTextArea();
		txtrVariable_1.setText("Variable 2:");
		txtrVariable_1.setForeground(Color.BLACK);
		txtrVariable_1.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrVariable_1.setEditable(false);
		txtrVariable_1.setColumns(10);
		txtrVariable_1.setBackground(SystemColor.menu);
		txtrVariable_1.setBounds(7, 128, 70, 20);
		contentPane.add(txtrVariable_1);
		
		txtrProporcioneLosValores = new JTextArea();
		txtrProporcioneLosValores.setText("Proporcione los valores a comparar");
		txtrProporcioneLosValores.setForeground(Color.BLACK);
		txtrProporcioneLosValores.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrProporcioneLosValores.setEditable(false);
		txtrProporcioneLosValores.setColumns(10);
		txtrProporcioneLosValores.setBackground(SystemColor.menu);
		txtrProporcioneLosValores.setBounds(10, 11, 219, 27);
		contentPane.add(txtrProporcioneLosValores);
	}
}
