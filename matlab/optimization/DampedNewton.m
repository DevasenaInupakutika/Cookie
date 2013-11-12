function [x_min, f_min] = DampedNewton(func, param, x0)
grad = gradient(func);
gradd = hessian(func, param);
x = x0;
for i = 1 : 100
    g = subs(grad, param, x);
    if norm(g) < 1e-6
        break
    end
    s = - inv(subs(gradd, param, x)) * g;
    x = LinearSearch(func, param, x, s);
end
x_min = double(x);
f_min = double(subs(func, param, x_min));