const canvas = document.getElementById("pong");
const context = canvas.getContext("2d");

const user = {
    x: 0,
    y: canvas.height / 2 - 100 / 2,
    width: 10,
    height: 100,
    color: "WHITE",
    score: 0
}
const com = {
    x: canvas.width - 10,
    y: canvas.height / 2 - 100 / 2,
    width: 10,
    height: 100,
    color: "WHITE",
    score: 0
}
const ball = {
    x: canvas.width / 2,
    y: canvas.height / 2,
    radius: 10,
    speed: 10,
    velocityx: 5,
    velocityy: 5,
    color: "WHITE",
}
const net = {
    x: canvas.width / 2 - 1,
    y: 0,
    width: 2,
    height: 10,
    color: "WHITE"
}


function drawRect(x, y, w, h, color) {
    context.fillStyle = color;
    context.fillRect(x, y, w, h);
}

function drawNet() {
    for (let i = 0; i <= canvas.height; i += 15) {
        drawRect(net.x, net.y + i, net.width, net.height, net.color);
    }
}

function drawCircle(x, y, r, color) {
    context.fillStyle = color;
    context.beginPath();
    context.arc(x, y, r, 0, Math.PI * 2, false);
    context.closePath();
    context.fill();
}

// drawCircle(100, 100, 50, "WHITE");

function drawText(text, x, y, color) {
    context.fillStyle = color;
    context.font = "45px fantasy";
    context.fillText(text, x, y);
}

// drawText("something", 300, 200, "WHITE");

function render() {
    drawRect(0, 0, canvas.width, canvas.height, "BLACK");

    drawNet();
    drawText(user.score, canvas.width / 4, canvas.height / 5, "WHITE");
    drawText(com.score, canvas.width / 4 * 3, canvas.height / 5, "WHITE");

    drawRect(user.x, user.y, user.width, user.height, user.color);
    drawRect(com.x, com.y, com.width, com.height, com.color);

    drawCircle(ball.x, ball.y, ball.radius, ball.color);

}

//collision
function collistion(b, p) {
    b.top = b.y - b.radius;
    b.bottom = b.y + b.radius;
    b.left = b.x - b.radius;
    b.right = b.x + b.radius;

    p.top = p.y;
    p.bottom = p.y + p.height;
    p.left = p.x;
    p.right = p.x + p.width;

    return b.right > p.left && b.bottom > p.top && b.left < p.right && b.top < p.bottom;
}

//user paddle
canvas.addEventListener("mousemove", movePaddle);

function movePaddle(evt) {
    let rect = canvas.getBoundingClientRect();

    user.y = evt.clientY - rect.top - user.height / 2;
}

//update : pos, mov, score ```
function update() {
    ball.x += ball.velocityx;
    ball.y += ball.velocityy;

    //simple ai
    let com_level = 0.1;
    com.y += (ball.y - (com.y + com.height / 2)) * com_level;
    if (ball.y + ball.radius > canvas.height || ball.y - ball.radius < 0) {
        ball.velocityy = -ball.velocityy;
    }

    let player = (ball.x < canvas.width / 2) ? user : com;

    if (collistion(ball, player)) {
        // ball.velocityx = -ball.velocityx;
        let collidePoint = ball.y - (player.y + player.height / 2);
        collidePoint = collidePoint / (player.height / 2);

        //각도측정
        let angleRad = collidePoint * Math.PI / 4;

        //충돌시 x 변경
        let dir = (ball.x < canvas.width / 2) ? 1 : -1;

        //val 변경
        ball.velocityx = dir * ball.speed * Math.cos(angleRad);
        ball.velocityy = ball.speed * Math.sin(angleRad);
        ball.speed += 0.5;
    }
    //update score
    if (ball.x - ball.radius < 0) {
        com.score++;
        resetBall();
    }
    else if (ball.x + ball.radius > canvas.width) {
        user.score++;
        resetBall();

    }

}

function resetBall() {
    ball.x = canvas.width / 2;
    ball.y = canvas.height / 2;

    ball.speed = 5;
    ball.velocityx = -ball.velocityx;
}

//game init
function game() {
    update();
    render();
}

const FPS = 50;
setInterval(game, 1000 / FPS); 
