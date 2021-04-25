package saveCMPM;

public class AddNhanKhauSave {

}
//package controller.nhankhau;
//
//import java.sql.SQLException;
//import java.util.List;
//import java.util.regex.Pattern;
//
//import javax.swing.JOptionPane;
//
//import javafx.collections.FXCollections;
//import javafx.event.ActionEvent;
//import javafx.fxml.FXML;
//import javafx.scene.control.CheckBox;
//import javafx.scene.control.TextField;
//import javafx.stage.Stage;
//import javafx.scene.Node;
//import models.NhanKhauModel;
//import models.QuanHeModel;
//import services.NhanKhauService;
//import services.QuanHeService;
//
//public class AddNhanKhau {
//	@FXML
//	private TextField tfId;
//	@FXML
//	private TextField tfTen;
//	@FXML
//	private TextField tfTuoi;
//	@FXML
//	private TextField tfCmnd;
//	@FXML
//	private TextField tfSdt;
//	@FXML
//	private TextField tfMaHoKhau;
//	@FXML
//	private TextField tfQuanHe;
//	@FXML
//	private CheckBox cboxChuHo;
//
//	public void addNhanKhau(ActionEvent event) throws ClassNotFoundException, SQLException {
//		Pattern pattern;
//		// Kiem tra nhap vao ID
////		if (tfId.getText().length() == 0) {
////			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào ID");
////			return;
////		} else if (tfId.getText().length() > 11) {
////			JOptionPane.showMessageDialog(null, "ID phải nhỏ hơn 11 số");
////			return;
////		} else {
////			for (int i = 0; i < tfId.getText().length(); i++) {
////				if ((int) tfId.getText().charAt(i) < 48 || (int) tfId.getText().charAt(i) > 57) {
////					JOptionPane.showMessageDialog(null, "ID phải là 1 số");
////					return;
////				}
////			}
////		}
//		pattern = Pattern.compile("\\d{1,11}");
//		if(!pattern.matcher(tfId.getText()).matches()) {
//			JOptionPane.showMessageDialog(null, "ID không chứa chữ cái và phải là 1 số nhỏ hơn 11 chữ số");
//			return;
//		}
//
//		// Kiem tra nhap vao Ten
//		if (tfTen.getText().length() == 0) {
//			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào Tên");
//			return;
//		} else {
//			if (tfTen.getText().length() > 50) {
//				JOptionPane.showMessageDialog(null, "Tên phải ít hơn 50 kí tự");
//				return;
//			}
//		}
//
//		// Kiem tra nhap vao Tuoi
//		if (tfTuoi.getText().length() == 0) {
//			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào Tuổi");
//			return;
//		} else if (tfTuoi.getText().length() > 11) {
//			JOptionPane.showMessageDialog(null, "Tuổi phải nhỏ hơn 11 số");
//			return;
//		} else {
//			for (int i = 0; i < tfTuoi.getText().length(); i++) {
//				if ((int) tfTuoi.getText().charAt(i) < 48 || (int) tfTuoi.getText().charAt(i) > 57) {
//					JOptionPane.showMessageDialog(null, "Tuổi phải là 1 số");
//					return;
//				}
//			}
//		}
//
//		// Kiem tra so CMND nhap vao
//		if (tfCmnd.getText().length() == 0) {
//			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào CMND");
//			return;
//		} else if (tfCmnd.getText().length() > 20) {
//			JOptionPane.showMessageDialog(null, "CMND phải nhỏ hơn 20 số");
//			return;
//		} else {
//			for (int i = 0; i < tfCmnd.getText().length(); i++) {
//				if ((int) tfCmnd.getText().charAt(i) < 48 || (int) tfCmnd.getText().charAt(i) > 57) {
//					JOptionPane.showMessageDialog(null, "CMND không bao gồm chữ");
//					return;
//				}
//			}
//		}
//		
//		// Kiem tra sdt nhap vao
//		if (tfSdt.getText().length() == 0) {
//			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào SĐT");
//			return;
//		} else if (tfSdt.getText().length() > 15) {
//			JOptionPane.showMessageDialog(null, "SĐT phải nhỏ hơn 15 số");
//			return;
//		} else {
//			for (int i = 0; i < tfSdt.getText().length(); i++) {
//				if ((int) tfSdt.getText().charAt(i) < 48 || (int) tfSdt.getText().charAt(i) > 57) {
//					JOptionPane.showMessageDialog(null, "SĐT không hợp lệ! Số điện thoại không gồm chữ");
//					return;
//				}
//			}
//		}
//
//		// Kiem tra ma ho nhap vao
//		if (tfMaHoKhau.getText().length() == 0) {
//			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào Mã hộ khẩu");
//			return;
//		} else if (tfMaHoKhau.getText().length() > 11) {
//			JOptionPane.showMessageDialog(null, "Mã hộ khẩu phải nhỏ hơn 11 số");
//			return;
//		} else {
//			for (int i = 0; i < tfMaHoKhau.getText().length(); i++) {
//				if ((int) tfMaHoKhau.getText().charAt(i) < 48 || (int) tfId.getText().charAt(i) > 57) {
//					JOptionPane.showMessageDialog(null, "Mã hộ khẩu phải là 1 số");
//					return;
//				}
//			}
//		}
//		
//
//		// Kiem tra Quan he nhap vao
//		if (tfQuanHe.getText().length() == 0) {
//			JOptionPane.showMessageDialog(null, "Bạn phải nhập vào Tên");
//			return;
//		} else {
//			if (tfQuanHe.getText().length() > 30) {
//				JOptionPane.showMessageDialog(null, "Tên phải ít hơn 30 kí tự");
//				return;
//			}
//		}
//		
//		// Ghi nhan gia tri da nhap vao hop le
//		int idInt = Integer.parseInt(tfId.getText());
//		String tenString = tfTen.getText();
//		int tuoiInt = Integer.parseInt(tfTuoi.getText());
//		String cmndString = tfCmnd.getText();
//		String sdtString = tfSdt.getText();
//		int mahokhauInt = Integer.parseInt(tfMaHoKhau.getText());
//		String quanheString = tfQuanHe.getText();
//		boolean isChuHo = cboxChuHo.isSelected();
//
//		if(!isChuHo) {
//			NhanKhauService nhanKhauService = new NhanKhauService();
//			QuanHeService quanHeService = new QuanHeService();
//
//			NhanKhauModel nhanKhauModel = new NhanKhauModel(idInt,cmndString,tenString,tuoiInt,sdtString);
//			QuanHeModel quanHeModel = new QuanHeModel(mahokhauInt, idInt, quanheString);
//			
//			nhanKhauService.add(nhanKhauModel);
//			quanHeService.add(quanHeModel);
//			
//			Stage stage = (Stage)((Node) event.getSource()).getScene().getWindow();
//	        stage.close();
//		}
//		
//				
//	}
//}
//
