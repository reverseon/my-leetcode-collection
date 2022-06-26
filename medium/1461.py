class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        ptwo = 1<<k
        a = set()
        picker = ptwo - 1
        ls = len(s)
        snum = int(s, 2)
        for i in range(ls - k + 1):
            ck = (snum & (picker << i)) >> i
            a.add(ck)
        return len(a) == (1<<k)