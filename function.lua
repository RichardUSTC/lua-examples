function foo(...)
    local sum = 0
    for i=1, select('#', ...) do
        sum = sum + select(i, ...)
    end
    return sum
end

function foo1(...)
    local sum = 0
    for i=1, #arg do
        sum = sum + arg[i]
    end
    return sum
end

function add(args)
    return (args.a or 0) + (args.b or 0)
end

print(foo(1, 2, 3))
print (foo(1, 2, 4, 8))
print(foo1(1, 2, 3))
print (foo1(1, 2, 4, 8))
print(add{["a"]=1, ["b"]= 2})
print(add{b=1, a=2})
