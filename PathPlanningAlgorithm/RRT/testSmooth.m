clc;  
clear;  
% (x,y)一系列离散点 构成路径原始  
x = [1 2 3 4 5 5 5 5 6 7 8 9 10 10 10 10 11 12 13 14 15 16 16 17];  
y = [7 7 7 7 7 6 5 4 4 4 4 4 4 3 2 2  1 1 1 2 2 3 3 4];  
alpha = 0.4; %  
beta = 0.6; % 平滑程度  
  
xi = x;% 初始化  
yi = y;  
% 迭代 8 次 
for k=1:8  
    for i = 2:1:(length(x)-1) % 不优化起始点S 和 终点 E  
       xi(i) = xi(i) + alpha*(x(i) - xi(i)) + beta*(xi(i-1) - 2*xi(i) + xi(i+1));  
       yi(i) = yi(i) + alpha*(y(i) - yi(i)) + beta*(yi(i-1) - 2*yi(i) + yi(i+1));  
    end  
end  
plot(x,y,xi,yi)  
grid on  