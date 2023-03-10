# import numpy as np
# import time
# import threading

# # 非线性状态转移函数
# def f(x, u):
#     x = x + u
#     y = x**2
#     return np.array([x, y])

# def h(x):
#     # 非线性测量函数
#     return np.array([x[1]])

# #z未知
# def ekf_callback(x, P, Q, R, u, z):
#     # 预测
#     x_pred = f(x, u) # 预测状态
#     F = np.array([[1, u], [0, 2*x[0]]]) # 状态转移矩阵的雅克比矩阵
#     P_pred = F @ P @ F.T + Q # 预测协方差矩阵

#     # 更新
#     y = z - h(x_pred) # 测量残差
#     H = np.array([[0, 1]]) # 测量函数的雅克比矩阵
#     S = H @ P_pred @ H.T + R # 测量噪声的协方差矩阵
#     K = P_pred @ H.T @ np.linalg.inv(S) # 卡尔曼增益
#     x = x_pred + K @ y # 更新状态向量
#     P = (np.eye(2) - K @ H) @ P_pred # 更新协方差矩阵

#     # 返回更新后的状态向量和协方差矩阵
#     return x, P

# # 模拟传感器数据生成器(需自己传入实时数据)(测量值需要替换为自己传入的实时数据)
# def data_generator():
#     while True:
#         yield np.array([1.5 + np.random.randn()]) # 生成随机测量值

# if __name__ == '__main__':
#     # 初始化状态向量和协方差矩阵
#     x = np.array([0, 0])
#     #print("test!!!!!!!!!!!", u)
#     P = np.eye(2)*1000
    
#     # 系统噪声和测量噪声的协方差矩阵
#     Q = np.eye(2)*0.01
#     R = np.array([[1]])
#     # 控制变量
#     u = 0.5

#     # 创建数据生成器和定时器
#     data_gen = data_generator()
#     interval = 1 # 时间步长
#     timer = threading.Timer(interval, lambda: None) # 初始化一个空定时器对象

#     # 实时更新状态向量和协方差矩阵
#     while True:
#         t_start = time.time()

#         # 读取测量值
#         z = next(data_gen)

#         # 调用EKF回调函数更新状态向量和协方差矩阵
#         x, P = ekf_callback(x, P, Q, R, u, z)

#         # 打印结果
#         print(f"x = {x}, P = {P}")

#         # 计算下一个定时器触发的时间
#         t_elapsed = time.time() - t_start
#         t_next = max(interval - t_elapsed, 0)
        
#         # 等待定时器触发
#         timer = threading.Timer(t_next, lambda: None)
#         timer.start()
#         timer.join()