package enumjava;

public class EnumDemo {
	enum Day{
		THU2, THU3, THU4, THU5, THU6, THU7;
		
	}
	
	enum Mua{
		XUAN(1), HA(2), THU(3), DONG(4);
		
		private int value;
		
		Mua(int value){
			this.value = value;
		}
		
		public static Mua getMua(int value) {
			for(Mua target : Mua.values()) {
				if(target.value == value)
					return target;
			}
			return Mua.XUAN;
		}
	}
	
	public static void main(String[] args) {
		for(Day day : Day.values()) {
			System.out.println(day);
		}
		
		System.out.println(Mua.getMua(2));
	}
	
	
}
