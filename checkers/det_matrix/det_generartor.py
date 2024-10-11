import numpy as np
import random

PATH = "/home/pabad-ap/miniRT/checkers/det_matrix/"
FILE = "tester.sh"
TRACE = "trace.txt"
SOLUTION = "det_matrix_checker.txt"

with open(PATH + FILE, "w") as file:
	file.write(f"#!/bin/bash\ncd {PATH};\n")
	with open(PATH + SOLUTION, "w") as sol:
		with open(PATH + TRACE, "w") as trace:
			for i in range(100):
				dim = np.random.randint(2, 5)
				a = np.random.randint(0, 50, [dim, dim])
				array_string = "../../miniRT " + str(dim) + " " + str(dim)  + " \"" + ';'.join([','.join(map(str, subarray)) for subarray in a]) + ";\"\n"
				file.write(array_string)
				sol.write(str(round(np.linalg.det(a))) + "\n")
				trace.write(f'MATRIZ: {str(dim)} {str(dim)} "{";".join([",".join(map(str, subarray)) for subarray in a]):<50}' +
					f'DETERMINANTE:{str(round(np.linalg.det(a)))}\n')
