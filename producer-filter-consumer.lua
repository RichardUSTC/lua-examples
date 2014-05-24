producer = coroutine.create(
    function ()
        while true do
            x = io.read()
            send(x)
        end
    end
)

function filter(prod)
	return coroutine.create(
		function ()
			i = 0
			while true do
				x = receive(prod)
				send(i .. ": " .. x)
				i = i + 1
			end
		end
	)
end

function consumer(prod)
    while true do
        x = receive(prod)
        print(x)
    end
end

function send(x)
    coroutine.yield(x)
end

function receive(prod)
    status, value = coroutine.resume(prod)
    return value
end

consumer(filter(producer))
