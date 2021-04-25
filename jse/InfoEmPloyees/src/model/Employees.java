package model;

public class Employees {
	private Integer emp_no;
	private String birth_date;
	private String first_name;
	private String last_name;
	private String gender;
	private String hire_date;
	private Integer salary;
	private String dept_no;
	private String title;
	
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public Integer getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public String getDept_no() {
		return dept_no;
	}

	public void setDept_no(String dept_no) {
		this.dept_no = dept_no;
	}

	public String getGender() {
		return gender;
	}

	public Employees(Integer emp_no, String birth_date, String first_name, String last_name, String gender, String hire_date
			, Integer salary, String dept_no, String title) {
		setEmp_no(emp_no);
		setBirth_date(birth_date);
		setFirst_name(first_name);
		setLast_name(last_name);
		setGender(gender);
		setHire_date(hire_date);
		setSalary(salary);
		setDept_no(dept_no);
		setTitle(title);
	}
	
	public Integer getEmp_no() {
		return emp_no;
	}
	
	public void setEmp_no(int emp_no) {
		this.emp_no = emp_no;
	}
	
	public String getBirth_date() {
		return birth_date;
	}
	
	public void setBirth_date(String birth_date) {
		this.birth_date = birth_date;
	}
	
	public String getFirst_name() {
		return first_name;
	}
	
	public void setFirst_name(String first_name) {
		this.first_name = first_name;
	}
	
	public String getLast_name() {
		return last_name;
	}
	
	public void setLast_name(String last_name) {
		this.last_name = last_name;
	}
	
	public void setGender(String gender) {
		this.gender = gender;
	}
	
	public String getHire_date() {
		return hire_date;
	}
	
	public void setHire_date(String hire_date) {
		this.hire_date = hire_date;
	}

	
	@Override
	public String toString() {
		return "Employee Number : " + this.emp_no + "\n"
				+ "Employee First Name : " + this.first_name + "\n"
				+ "Employee Last Name : " + this.last_name + "\n"
				+ "Employee gender : " + this.gender + "\n"
				+ "Employee hire date : " + this.hire_date;
	}
}
