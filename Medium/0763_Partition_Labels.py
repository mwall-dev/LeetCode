from typing import List


class Solution:

    def get_partition_end(self, S: str, partition_start):
        """ Function to return end of partition index given a starting point"""

        # Set initial naive partition end based on first letter
        letter = S[partition_start]
        partition_end = S.rfind(letter) 
        i = partition_start + 1

        while i < partition_end:
            # Look in the space after the partition for characters in the partition.
            latest_index = S.rfind(S[i], partition_end)
            # If you've found one outside the partition, you need to extend the partition end.
            if latest_index != -1:
                partition_end = latest_index
            i += 1
        
        return partition_end



    def partitionLabels(self, S: str) -> List[int]:

        partitions = [] # Holds result
        partition_start = 0
        
        
        partition_end = self.get_partition_end(S, partition_start)
        partitions.append(partition_end - partition_start + 1)
        partition_start = partition_end + 1
    
        while partition_start != len(S):
            partition_end = self.get_partition_end(S, partition_start)
            partitions.append(partition_end - partition_start + 1)
            partition_start = partition_end + 1

        return partitions





if __name__ == "__main__":
    s = Solution()
    print(s.partitionLabels("aaabcdbadbeeef"))