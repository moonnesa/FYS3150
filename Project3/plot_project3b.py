# -*- coding: utf-8 -*-
"""
Created on Tue Oct 23 13:23:39 2018

@author: Mooni
"""
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import numpy as np

"""Script for plotting eigenvalues as a function of omega_r and logarithmic
    plot of iterations as a function of n"""

rho = []
eigenvec = []
c =[]

with open("Euler_array.txt", "r") as file:
    # next(file)
    for line in file:
        col = line.split()
        rho.append(float(col[0]))
        eigenvec.append(float(col[1]))
        c.append(float(col[2]))

rho_array = np.array(rho)
eigenvec_array = np.array(eigenvec)
c_array = np.array(c)
file.close()

x_list = []
y_list = []
z_list = []

with open("Verlet_array.txt", "r") as file1:
    # next(file)
    for line in file1:
        col = line.split()
        x_list.append(float(col[0]))
        y_list.append(float(col[1]))
        z_list.append(float(col[2]))

x = np.array(x_list)
y = np.array(y_list)
z = np.array(z_list)
file1.close()

fig = plt.figure()
ax1 = fig.add_subplot(111, projection='3d')
#ax1.plot3D(x,y,z,'blue', label='Earth')
#ax1.plot3D(rho_array ,eigenvec_array,c_array,'blue', label='Earth')
ax1.plot3D(x, y, z,'red', label='Earth')
ax1.plot([0],[0],[0],markerfacecolor='yellow', markeredgecolor='yellow', marker='o', markersize=20, alpha=0.6, label='Sun')
ax1.legend(loc='upper left')
ax1.axis('equal')

plt.style.use('ggplot')
fig, ax = plt.subplots()
ax.plot(0,0,marker = 'o',markersize=30, color = 'yellow', label='Sun')
#ax.plot(rho_array, eigenvec_array,marker = 'o',markersize=1, color = 'red', label='Earth')
ax.plot(x, y, marker = 'o', markersize=0.00001, color = 'blue', label='Earth')
plt.xlim([-1.5, 1.5])
plt.ylim([-1.5, 1.5])
ax.axis('equal')
plt.legend(loc='upper right')
# ax.set_title("Energy ground states for different $\\omega_r$")
# ax.set_xlabel("$\\omega_r$")
# ax.set_ylabel("E($\\omega_r$)")
# ax.set_title("Ground state of a harmonic oscillator potential")
# ax.set_xlabel("$\\rho$")
# ax.set_ylabel("u($\\rho$)")


# fig, ax = plt.subplots()
# ax.plot(np.log(n), np.log(iter))
# ax.set_title("Logarithmic plot of iterations against dimension n")
# ax.set_xlabel("log(n)")
# ax.set_ylabel("log(iterations)")
plt.show()