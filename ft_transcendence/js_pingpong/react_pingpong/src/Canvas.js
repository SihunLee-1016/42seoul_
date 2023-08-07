import { useEffect, useRef, useState } from 'react'



function Canvas(props) {
    const ref = useRef();

    console.log(props)

    function drawRect(context, x, y, w, h, color) {
        context.fillStyle = color;
        context.fillRect(x, y, w, h);
    }

    function drawNet(context, net) {
        for (let i = 0; i <= props.height; i += 15) {
            drawRect(context, net.x, net.y + i, net.width, net.height, net.color);
        }
    }

    useEffect(() => {
        const canvas = ref.current;
        const context = canvas.getContext('2d')
        drawRect(context, 0, 0, props.width, props.height, "BLACK")
        drawNet(context, net);

        return (<update user={user} com={com} ball={ball} />);
    }, [])

    const [user, setUser] = useState({
        x: 0,
        y: props.height / 2 - 100 / 2,
        width: 10,
        height: 100,
        color: "WHITE",
        score: 0
    })

    const [com, setCom] = useState({
        x: props.width - 10,
        y: props.height / 2 - 100 / 2,
        width: 10,
        height: 100,
        color: "WHITE",
        score: 0
    })

    const [ball, setBall] = useState({
        x: props.width / 2,
        y: props.height / 2,
        radius: 10,
        speed: 10,
        velocityx: 5,
        velocityy: 5,
        color: "WHITE",
    })

    const net = {
        x: props.width / 2 - 1,
        y: 0,
        width: 2,
        height: 10,
        color: "WHITE"
    }

    // drawRect(context, user.x, user.y, user.width, user.height, user.color);
    // drawRect(context, com.x, com.y, com.width, com.height, com.color);
    return (<canvas ref={ref} {...props} />)    //왜 ref를 Canvas를 호출한 컴포넌트로 줘야할까..?

}

export default Canvas