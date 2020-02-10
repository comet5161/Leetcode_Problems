class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        '''
        if(len(matrix) > 0):
            return [*matrix.pop(0)] + self.spiralOrder([*zip(*matrix)][::-1]) 
            #[*zip(*matrix)][::-1]表示矩阵逆时针旋转90度,先转置再倒置
        else :
            return []
        '''
        if(any(matrix) == False):
            return []
        
        rows = len(matrix)
        cols = len(matrix[0])
        res = []

        step_r = [0,1,0,-1]
        step_c = [1,0,-1,0]
        r,c = 0,-1
        direct = 0
        steps = cols
        while(cols > 0 and rows > 0):
            for j in range(steps):
                r, c = r + step_r[direct], c + step_c[direct] 
                res.append(matrix[r][c])
            if((direct % 2) == 0):
                rows -= 1
                steps = rows
            else :
                cols -= 1
                steps = cols
            direct = (direct + 1) % 4
        return res