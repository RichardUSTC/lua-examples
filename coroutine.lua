co = coroutine.create(
    function (a, b, c)
        coroutine.yield(c, b, a)
    end
)

print(coroutine.resume(co, 1, 2, 3))
