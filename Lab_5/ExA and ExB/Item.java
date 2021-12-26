/* ENSF 480 - Lab 5 Exercise A and B
 * 	
 * 		File Name: Item.java
 * 		Assignment Lab 5 exercise A
 * 		Completed By: Matthew Ho and Alexander Sembrat
 * 		Submission Date: 11/4/2021
 * 
 */

class Item <E extends Number & Comparable<E>>{
	private E item;
	public Item(E value) {
		item = value;
	}
	
	public void setItem(E value){
		item = value;
	}
	
	public E getItem(){
		return item;
	}

	public int compareTo(Item<E> e) {
		return this.getItem().compareTo(e.getItem());
	}
}
