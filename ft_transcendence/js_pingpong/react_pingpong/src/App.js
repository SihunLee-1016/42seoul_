
// // const canvas = document.getElementById("root");
// const canvas = document.getElementById("pong");
// const context = canvas.getContext("2d");

// canvas.addEventListener("mousemove", movePaddle);

// function drawRect(x, y, w, h, color) {
//   context.fillStyle = color;
//   context.fillRect(x, y, w, h);
// }

// function drawNet(net) {
//   for (let i = 0; i <= canvas.height; i += 15) {
//     drawRect(net.x, net.y + i, net.width, net.height, net.color);
//   }
// }

// function drawCircle(x, y, r, color) {
//   context.fillStyle = color;
//   context.beginPath();
//   context.arc(x, y, r, 0, Math.PI * 2, false);
//   context.closePath();
//   context.fill();
// }

// function drawText(text, x, y, color) {
//   context.fillStyle = color;
//   context.font = "45px fantasy";
//   context.fillText(text, x, y);
// }

// // function render(user, com, ball) {
// //   drawRect(0, 0, canvas.width, canvas.height, "BLACK");

// //   drawNet();
// //   drawText(user.score, canvas.width / 4, canvas.height / 5, "WHITE");
// //   drawText(com.score, canvas.width / 4 * 3, canvas.height / 5, "WHITE");

// //   drawRect(user.x, user.y, user.width, user.height, user.color);
// //   drawRect(com.x, com.y, com.width, com.height, com.color);

// //   drawCircle(ball.x, ball.y, ball.radius, ball.color);

// // }

// function App() {

//   const [user, setUser] = React.useState(
//     {
//       x: 0,
//       y: canvas.height / 2 - 100 / 2,
//       width: 10,
//       height: 100,
//       color: "WHITE",
//       score: 0
//     }
//   );

//   const [com, setCom] = React.useState(
//     {
//       x: canvas.width - 10,
//       y: canvas.height / 2 - 100 / 2,
//       width: 10,
//       height: 100,
//       color: "WHITE",
//       score: 0
//     }
//   );

//   const [ball, setBall] = React.useState(
//     {
//       x: canvas.width / 2,
//       y: canvas.height / 2,
//       radius: 10,
//       speed: 10,
//       velocityx: 5,
//       velocityy: 5,
//       color: "WHITE",
//     }
//   );

//   const [net, setNet] = React.useState({
//     x: canvas.width / 2 - 1,
//     y: 0,
//     width: 2,
//     height: 10,
//     color: "WHITE"
//   });

//   function render() {
//     drawRect(0, 0, canvas.width, canvas.height, "BLACK");
//     drawNet(net);
//     drawText(user.score, canvas.width / 4, canvas.height / 5, "WHITE");
//     drawText(com.score, canvas.width / 4 * 3, canvas.height / 5, "WHITE");

//     drawRect(user.x, user.y, user.width, user.height, user.color);
//     drawRect(com.x, com.y, com.width, com.height, com.color);

//     drawCircle(ball.x, ball.y, ball.radius, ball.color);
//   }

//   render(user, com, ball)
//   // return (render(user, com, ball)
//   // )

// }

// export default App;


import React, { useState, useRef } from 'react'
import ReactDOM from 'react-dom/client';
import Canvas from "./Canvas"

function App() {

  // const ref = useRef();
  // const canvas = ref.current;
  // const context = canvas.getContext('2d')

  // return (<Canvas width="600" height="400" ref={ref} can={canvas} context={context} />
  return (<Canvas width="600" height="400" />
  )
}
export default App;