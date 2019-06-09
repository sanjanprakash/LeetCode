class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        all_perms = set()
        for i in range(1,len(tiles)+1) :
            all_perms = all_perms.union(set(itertools.permutations(tiles,i)))
        return len(all_perms)
        
