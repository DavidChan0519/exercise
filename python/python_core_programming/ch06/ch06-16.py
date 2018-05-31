def matrix_add(X,Y):
	for i in range(len(X)):
		for j in range(len(X[0])):
			result[i][j]=X[i][j]+Y[i][j]


A=[[1,2,3,4],[5,6,7,8],[9,10,11,12]]
B=[[11,12,13,14],[15,16,17,18],[19,20,21,22]]

result = [[0,0,0,0],
         [0,0,0,0],
         [0,0,0,0]]

matrix_add(A,B)

print result


