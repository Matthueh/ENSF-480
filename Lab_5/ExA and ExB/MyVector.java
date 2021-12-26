/*	
 * 		File Name: MyVector.java
 * 		Assignment Lab 5 exercise A and B
 * 		Completed By: Matthew Ho and Alexander Sembrat
 * 		Submission Date: 11/4/2021
 */
import java.util.ArrayList;

public class MyVector<E extends Number & Comparable<E> >{
	
	//We also need a private data member named sorter
	private ArrayList<Item<E>> storageM;
	private Sorter<E> sorter;
	//Class constructor takes in one integer to allocate n spaces in an array;
	public MyVector(int n) {
			storageM = new ArrayList<Item<E>>(n);
	}
	
	public MyVector(ArrayList<Item<E>> arr) {
		//create a new ArrayList for storageM
		storageM = new ArrayList<Item<E>>(arr.size());
		//Now we should add each individual item so that the whole thing gets filled
		for(int i = 0; i < arr.size() ; i++) {
			storageM.add(arr.get(i));
		}
	}
	
	public void add(Item<E> value) {
		storageM.add(value);
	}
	
	//Set sorter to the sort technique that we are interested in.
	public void setSortStrategy(Sorter<E> s) {
		sorter = s;
	}
	
	//Depending on what sort is, we want to perform the sorting depending on what we assigned it.
	public void performSort() {
		sorter.sort(storageM);
	}
	
	public void display() {
		for(int i = 0; i < storageM.size(); i++) {
			System.out.print(storageM.get(i).getItem()  + "		");
		}
	}
	//Copy constructor that takes in an array list object. 
	//It will then make a copy of this array list object.
	

}
