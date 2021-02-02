import java.util.{Date, Locale}
import java.text.DateFormat._

object Hello {
	def print(message : String) = {
		println(message)
	}

    def main(args: Array[String]) = {
        print("hello world")	
        val now = new Date
        val df = getDateInstance(LONG, Locale.FRANCE)
    	println(df format now)	
    }
}


