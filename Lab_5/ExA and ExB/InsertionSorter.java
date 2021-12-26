/*	
 * 		File Name: InsertionSorter.java
 * 		Assignment Lab 5 exercise A
 * 		Completed By: Matthew Ho and Alexander Sembrat
 * 		Submission Date: 11/4/2021
 */
import java.util.ArrayList;

public class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
	
	@Override
	public void sort(ArrayList<Item<E>> storageM) {
		//This will implement the insertion sorting technique
		for(int i = 1; i < storageM.size(); ++i) {
			Item<E> key = (Item<E>) storageM.get(i);
			int j = i - 1;
			while( j >= 0 && storageM.get(j).compareTo(key) > 0) {
				storageM.set(j+1, storageM.get(j));
				j = j - 1;
			}
			storageM.set(j+1, key);
		}
		
	}

	
}
