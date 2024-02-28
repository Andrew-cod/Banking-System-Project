int binarySearch(int* nums, int size, int target) {
	int left=0;
	int right=size-1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target == nums[mid]) {
			return mid;
		}
		else {
			if (target < nums[mid]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}

	}
	return -1;
}

int binarySearchModified(int* nums, int size, int target, int findLeft) {

}

void searchRange(int* nums, int size, int target, int* index_left, int* index_right) {
    int left = binarySearchModified(nums, size, target, 1);
    if (left == -1) {
        *index_left = -1;
        *index_right = -1;
    }

    int right = binarySearchModified(nums, size, target, 0);
    *index_left = left;
    *index_right = right;
}

