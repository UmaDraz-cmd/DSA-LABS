import numpy as np
def generate_random_number(x_list, p):
    r=np.random.rand() 
    p_so_far=0
    for i in range(len(p)): 
        if r<=p_so_far+p[i]: 
            return x_list[i]
        p_so_far+=p[i]
    


x_list= np.array([6,2,-1,0])
p= [0.3,0.4,0.1,0.2]
y= generate_random_number(x_list, p)
