import React from 'react';
import { Container, Row, Col } from '@mui';

function HomePage() {
  return (
    <Container>
      <Row className="justify-content-center align-items-center" style={{ height: "100vh" }}>
        <Col md={6} className="text-center">
          <h1>Welcome to Cyber Brain</h1>
          <p>Your one-stop solution for organizing your projects and notes</p>
        </Col>
      </Row>
    </Container>
  );
}

export default HomePage;
