
import React, { useEffect, useRef } from 'react';
import './App.css';
const canvas: HTMLCanvasElement | null = document.getElementById("pong") as HTMLCanvasElement | null;
const context: CanvasRenderingContext2D | null = canvas?.getContext("2d") as CanvasRenderingContext2D;

interface Paddle {
  x: number;
  y: number;
  width: number;
  height: number;
  color: string;
  score: number;
}

const user: Paddle = {
  x: 0,
  y: canvas ? canvas.height / 2 - 100 / 2 : 0,
  width: 10,
  height: 100,
  color: "WHITE",
  score: 0,
};

const com: Paddle = {
  x: canvas ? canvas.width - 10 : 0,
  y: canvas ? canvas.height / 2 - 100 / 2 : 0,
  width: 10,
  height: 100,
  color: "WHITE",
  score: 0,
};

const ball = {
  x: canvas ? canvas.width / 2 : 0,
  y: canvas ? canvas.height / 2 : 0,
  radius: 10,
  speed: 10,
  velocityx: 5,
  velocityy: 5,
  color: "WHITE",
};

const net = {
  x: canvas ? canvas.width / 2 - 1 : 0,
  y: 0,
  width: 2,
  height: 10,
  color: "WHITE",
};

function drawRect(x: number, y: number, w: number, h: number, color: string) {
  if (context) {
    context.fillStyle = color;
    context.fillRect(x, y, w, h);
  }
}

function drawNet() {
  if (context) {
    for (let i = 0; i <= (canvas ? canvas.height : 0); i += 15) {
      drawRect(net.x, net.y + i, net.width, net.height, net.color);
    }
  }
}

function drawCircle(x: number, y: number, r: number, color: string) {
  if (context) {
    context.fillStyle = color;
    context.beginPath();
    context.arc(x, y, r, 0, Math.PI * 2, false);
    context.closePath();
    context.fill();
  }
}

function drawText(text: string, x: number, y: number, color: string) {
  if (context) {
    context.fillStyle = color;
    context.font = "45px fantasy";
    context.fillText(text, x, y);
  }
}

function render() {
  if (context) {
    drawRect(0, 0, canvas ? canvas.width : 0, canvas ? canvas.height : 0, "BLACK");

    drawNet();
    drawText(user.score.toString(), canvas ? canvas.width / 4 : 0, canvas ? canvas.height / 5 : 0, "WHITE");
    drawText(com.score.toString(), canvas ? (canvas.width / 4) * 3 : 0, canvas ? canvas.height / 5 : 0, "WHITE");

    drawRect(user.x, user.y, user.width, user.height, user.color);
    drawRect(com.x, com.y, com.width, com.height, com.color);

    drawCircle(ball.x, ball.y, ball.radius, ball.color);
  }
}

function collistion(b: typeof ball, p: Paddle) {
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

function movePaddle(evt: MouseEvent) {
  if (canvas) {
    let rect = canvas.getBoundingClientRect();

    user.y = evt.clientY - rect.top - user.height / 2;
  }
}

if (canvas) {
  canvas.addEventListener("mousemove", movePaddle);
}

function update() {
  ball.x += ball.velocityx;
  ball.y += ball.velocityy;

  let com_level = 0.1;
  if (canvas) {
    com.y += (ball.y - (com.y + com.height / 2)) * com_level;
    if (ball.y + ball.radius > canvas.height || ball.y - ball.radius < 0) {
      ball.velocityy = -ball.velocityy;
    }

    let player = (ball.x < canvas.width / 2) ? user : com;

    if (collistion(ball, player)) {
      let collidePoint = ball.y - (player.y + player.height / 2);
      collidePoint = collidePoint / (player.height / 2);

      let angleRad = collidePoint * Math.PI / 4;

      let dir = (ball.x < canvas.width / 2) ? 1 : -1;

      ball.velocityx = dir * ball.speed * Math.cos(angleRad);
      ball.velocityy = ball.speed * Math.sin(angleRad);
      ball.speed += 0.5;
    }

    if (ball.x - ball.radius < 0) {
      com.score++;
      resetBall();
    } else if (ball.x + ball.radius > canvas.width) {
      user.score++;
      resetBall();
    }
  }
}

function resetBall() {
  if (canvas) {
    ball.x = canvas.width / 2;
    ball.y = canvas.height / 2;

    ball.speed = 5;
    ball.velocityx = -ball.velocityx;
  }
}

function game() {
  update();
  render();
}

const FPS = 50;
setInterval(game, 1000 / FPS);

