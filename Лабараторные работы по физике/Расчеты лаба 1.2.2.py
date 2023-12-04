import numpy as np

beta = np.array([0.669, 1.067, 1.658, 1.907, 2.3])
M = np.array([0.0121, 0.0189, 0.026, 0.031, 0.037])

sr_beta_M = sum(beta*M)/5
sr_beta = sum(beta)/5
sr_M = sum(M)/5
sr_M_kv = sum(M**2)/5
sr_kv_M = sr_M**2
sr_beta_kv = sum(beta**2)/5
sr_kv_beta = sr_beta**2

b = (sr_beta_M - sr_beta*sr_M)/(sr_M_kv - sr_kv_M)
a = sr_beta - b*sr_M
print(a, b)

sigma_b = (1/(5**0.5))*((sr_beta_kv - sr_kv_beta)/(sr_M_kv - sr_kv_M) - b**2)**0.5
sigma_a = sigma_b*((sr_M_kv - sr_kv_M)**0.5)
print(sigma_a, sigma_b)

I = np.array([0.0182, 0.0159, 0.0131, 0.02201])
R_kv = (np.array([0.17, 0.15, 0.13, 0.18]))**2

sr_I_R = sum(I*R_kv)/4
sr_I = sum(I)/4
sr_R = sum(R_kv)/4
sr_R_kv = sum(R_kv**2)/4
sr_kv_R = sr_R**2
sr_I_kv = sum(I**2)/4
sr_kv_I = sr_I**2

b_1 = (sr_I_R - sr_I*sr_R)/(sr_R_kv - sr_kv_R)
a_1 = sr_I - b_1*sr_R
print(a_1, b_1)

sigma_b_1 = 0.5*(((sr_I_kv - sr_kv_I)/(sr_R_kv - sr_kv_R) - b_1**2)**0.5)
sigma_a_1 = sigma_b_1*(sr_R_kv - sr_kv_R)
print(sigma_a_1, sigma_b_1)