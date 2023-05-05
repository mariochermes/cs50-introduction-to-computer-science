import React, { useRef, useEffect } from 'react';

const Line = ({ start, end }) => {
  const canvasRef = useRef(null);

  useEffect(() => {
    const canvas = canvasRef.current;
    const ctx = canvas.getContext('2d');
    
    const startX = start.x;
    const startY = start.y;
    const endX = end.x;
    const endY = end.y;

    const width = Math.abs(endX - startX);
    const height = Math.abs(endY - startY);

    canvas.width = width;
    canvas.height = height;

    ctx.beginPath();
    ctx.moveTo(0, 0);

    if (startX < endX && startY < endY) {
      ctx.lineTo(width, 0);
      ctx.lineTo(width, height);
      ctx.lineTo(0, height);
    } else if (startX < endX && startY > endY) {
      ctx.lineTo(width, 0);
      ctx.lineTo(width, height);
      ctx.lineTo(0, height);
    } else if (startX > endX && startY < endY) {
      ctx.lineTo(width, height);
      ctx.lineTo(0, height);
      ctx.lineTo(0, 0);
    } else {
      ctx.lineTo(width, height);
      ctx.lineTo(0, height);
      ctx.lineTo(0, 0);
    }

    ctx.stroke();
    ctx.beginPath();
    ctx.arc(0, 0, 5, 0, 2 * Math.PI);
    ctx.fill();
    ctx.beginPath();
    ctx.arc(width, height, 5, 0, 2 * Math.PI);
    ctx.fill();
  }, [start, end]);

  return (
    <canvas ref={canvasRef} style={{ position: 'absolute', left: Math.min(start.x, end.x), top: Math.min(start.y, end.y) }} />
  );
};

export default Line;
