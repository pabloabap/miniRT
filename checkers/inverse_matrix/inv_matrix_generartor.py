import numpy as np
from numpy.linalg import inv
import random

PATH = "/home/pabad-ap/miniRT/checkers/inverse_matrix/"
FILE = "tester.sh"
TRACE = "trace.txt"
SOLUTION = "inv_matrix_checker.txt"

with open(PATH + FILE, "w") as file:
	file.write(f"#!/bin/bash\ncd {PATH};\n")
	with open(PATH + SOLUTION, "w") as sol:
		with open(PATH + TRACE, "w") as trace:
			for i in range(100):
				a = np.random.randint(0, 50, [4, 4])
				b = inv(a)
				array_string = "../../miniRT " + str(4) + " " + str(4)  + " \"" + ';'.join([','.join(map(str, subarray)) for subarray in a]) + ";\"\n"
				file.write(array_string)
				inv_str = ""
				for i in range(len(b)):
					for j in range(len(b[i])):
						inv_str += f'{b[i][j]:0.6f},'
					inv_str += "\n"
				sol.write(inv_str)
				trace.write(f'MATRIZ: {str(4)} {str(4)} "{";".join([",".join(map(str, subarray)) for subarray in a]):<50}' + "\n" +
					f'INV:\n{inv_str}')