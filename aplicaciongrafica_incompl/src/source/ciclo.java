package source;
import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JTextArea;
import java.awt.SystemColor;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JButton;


public class ciclo extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_3;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ciclo frame = new ciclo();
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
	public ciclo() {
		setTitle("Ciclo (repeat)");
		setEnabled(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 230, 260);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(88, 57, 86, 20);
		contentPane.add(textField);
		textField.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setColumns(10);
		textField_3.setBounds(88, 145, 86, 20);
		contentPane.add(textField_3);
		
		JComboBox comboBox = new JComboBox();
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"", ">", "<", "==", ">=", "<="}));
		comboBox.setToolTipText("");
		comboBox.setBounds(88, 102, 86, 20);
		contentPane.add(comboBox);
		
		JTextArea txtrLaVariable = new JTextArea();
		txtrLaVariable.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrLaVariable.setText("La variable:");
		txtrLaVariable.setForeground(Color.BLACK);
		txtrLaVariable.setEditable(false);
		txtrLaVariable.setColumns(10);
		txtrLaVariable.setBackground(SystemColor.menu);
		txtrLaVariable.setBounds(10, 58, 70, 20);
		contentPane.add(txtrLaVariable);
		
		JTextArea textArea = new JTextArea();
		textArea.setText("La variable:");
		textArea.setForeground(Color.BLACK);
		textArea.setFont(new Font("Tahoma", Font.PLAIN, 11));
		textArea.setEditable(false);
		textArea.setColumns(10);
		textArea.setBackground(SystemColor.menu);
		textArea.setBounds(10, 145, 70, 20);
		contentPane.add(textArea);
		
		JTextArea txtrSea = new JTextArea();
		txtrSea.setText("sea");
		txtrSea.setForeground(Color.BLACK);
		txtrSea.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrSea.setEditable(false);
		txtrSea.setColumns(10);
		txtrSea.setBackground(SystemColor.menu);
		txtrSea.setBounds(10, 104, 70, 20);
		contentPane.add(txtrSea);
		
		JTextArea txtrRepetirElCiclo = new JTextArea();
		txtrRepetirElCiclo.setText("Repetir el ciclo hasta que:");
		txtrRepetirElCiclo.setForeground(Color.BLACK);
		txtrRepetirElCiclo.setFont(new Font("Tahoma", Font.PLAIN, 11));
		txtrRepetirElCiclo.setEditable(false);
		txtrRepetirElCiclo.setColumns(10);
		txtrRepetirElCiclo.setBackground(SystemColor.menu);
		txtrRepetirElCiclo.setBounds(10, 11, 164, 20);
		contentPane.add(txtrRepetirElCiclo);
		
		JButton btnNewButton = new JButton("Terminar");
		btnNewButton.setBounds(65, 185, 89, 23);
		contentPane.add(btnNewButton);
	}
}
