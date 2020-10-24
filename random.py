import numpy as np
random_matrix_array = np.random.randint(100,200,size=(6,6))
for row in random_matrix_array:
	print(*row)
