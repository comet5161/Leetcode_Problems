class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        #return matrix and [*matrix.pop(0)] + self.spiralOrder([*zip(*matrix)][::-1])
        res = []
        rows = len(matrix)
        if(rows == 0):
            return res
        cols = len(matrix[0])
        if(cols == 0):
            return res
        step_r = [0,1,0,-1]
        step_c = [1,0,-1,0]
        r = 0
        c = 0 
        direct = 0
        for i in range(rows*cols):
            res.append(matrix[r][c])
            matrix[r][c] = None
            r0 = r
            c0 = c
            r = r + step_r[direct]
            c = c + step_c[direct]
            if (r < 0 or c < 0 or r >= rows or c >= cols or matrix[r][c] == None):
                direct = (direct + 1) % 4
                r = r0 + step_r[direct]
                c = c0 + step_c[direct]
        return res