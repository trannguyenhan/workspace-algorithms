package bai6;

import java.sql.Date;

public class HoaDon {
	private int maHoaDon;
	private int maNV;
	private int maKhachHang;
	private String dsMatHang;
	private double tongGia;
	private Date ngayMua;
	
	public int getMaHoaDon() {
		return maHoaDon;
	}
	
	public void setMaHoaDon(int maHoaDon) {
		this.maHoaDon = maHoaDon;
	}
	
	public int getMaNV() {
		return maNV;
	}
	
	public void setMaNV(int maNV) {
		this.maNV = maNV;
	}
	
	public int getMaKhachHang() {
		return maKhachHang;
	}
	
	public void setMaKhachHang(int maKhachHang) {
		this.maKhachHang = maKhachHang;
	}
	
	public String getDsMatHang() {
		return dsMatHang;
	}
	
	public void setDsMatHang(String dsMatHang) {
		this.dsMatHang = dsMatHang;
	}
	
	public double getTongGia() {
		return tongGia;
	}
	
	public void setTongGia(double tongGia) {
		this.tongGia = tongGia;
	}
	
	public Date getNgayMua() {
		return ngayMua;
	}
	
	public void setNgayMua(Date ngayMua) {
		this.ngayMua = ngayMua;
	}
}	
