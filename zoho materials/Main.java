
import java.util.*;  
// public class Main{  
// public static void main(String args[]){  
// //Creating HashSet and adding elements  
// HashSet<String> set=new HashSet<String>();  
// set.add("Ravi");  
// set.add("Vijay");  
// set.add("Ravi");  
// set.add("Ajay");
// set.add(null);  
// set.add(null);  
// //Traversing elements  
// Iterator<String> itr=set.iterator();  
// while(itr.hasNext()){  
// System.out.println(itr.next());  
// }  
// } 
// }


import java.util.*;  
public class Main{  
public static void main(String args[]){  
LinkedHashSet<String> set=new LinkedHashSet<String>();  
set.add("Ravi");  
set.add("Vijay");  
set.add("Ravi");  
set.add("Ajay"); 
set.add(null); 
set.add(null);  
Iterator<String> itr=set.iterator();  
while(itr.hasNext()){  
System.out.println(itr.next());  
}  
}  
}  