/*	
 * 		File Name: Sorter.java
 * 		Assignment Lab 5 exercise A and B
 * 		Completed By: Matthew Ho and Alexander Sembrat
 * 		Submission Date: 11/4/2021
 */
import java.util.ArrayList;

public interface Sorter<E extends Number & Comparable<E>> {
	//DemoStrategyPattern will call a sorting technique that has been extended
	//This class should be able to call the sorting function of the different classes
	public void sort(ArrayList<Item<E>> storageM);

}
