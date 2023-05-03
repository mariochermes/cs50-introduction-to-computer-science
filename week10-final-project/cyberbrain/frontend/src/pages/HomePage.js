import React from 'react';
import { Container, Row, Col } from 'react-bootstrap';

const HomePage = () => {
  return (
    <Container fluid className="w-75 h-100">
      <Row className="justify-content-center align-items-center" style={{ height: "100vh" }}>
        <Col className="text-center">
          <h1>Welcome to Cyber Brain</h1>
          <p>A second brain to organize your life.</p>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
