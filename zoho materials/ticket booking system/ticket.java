import java.util.*;
class ticket{
	int ticketId;
	String mvName;
	String mvTime;
	String mvPrice;
	int tofper; //total no of seats
	int[] bookseats; //no seat
	ticket(int ticketId,String mvName,String mvTime, String mvPrice,int tofper,int[] bookseats){
		this.ticketId=ticketId;
		this.mvName=mvName;
		this.mvTime=mvTime;
		this.mvPrice=mvPrice;
		this.tofper=tofper;
		this.bookseats=bookseats;
	}
	public void showTicket(){
		System.out.println("-------------------------------------------------------");
		System.out.println("Ticket Id : "+ticketId);
		System.out.println("Movie Name : "+mvName);
		System.out.println("Movie Time : "+mvTime);
		System.out.println("Ticket Price : "+mvPrice);
		System.out.println("Total no of persons :"+tofper);
		System.out.println("seats are :"+Arrays.toString(bookseats));
		System.out.println("-------------------------------------------------------");
		
	}

}