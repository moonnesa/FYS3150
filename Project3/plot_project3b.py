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


with open("Euler_array.txt", "r") as file:
    # next(file)
    for line in file:
        col = line.split()
        rho.append(float(col[0]))
        eigenvec.append(float(col[1]))

rho_array = np.array(rho)
eigenvec_array = np.array(eigenvec)

with open("Verlet_array.txt", "r") as file:
    # next(file)
    for line in file:
        col = line.split()
        rho.append(float(col[0]))
        eigenvec.append(float(col[1]))

x = np.array(rho)
y = np.array(eigenvec)

fig = plt.figure()
ax1 = fig.add_subplot(111, projection='3d')
ax1.plot3D(x,y,0,'blue', label='Earth')
ax1.plot([0],[0],[0],markerfacecolor='yellow', markeredgecolor='yellow', marker='o', markersize=20, alpha=0.6, label='Sun')
ax1.legend(loc='upper left')

plt.style.use('ggplot')
fig, ax = plt.subplots()
ax.plot(0,0,marker = 'o',markersize=30, color = 'yellow', label='Sun')
#ax.plot(rho_array, eigenvec_array,marker = 'o',markersize=10, color = 'blue', label='Earth')
ax.plot(x, y,marker = 'o',markersize=0.00001, color = 'blue', label='Earth')
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