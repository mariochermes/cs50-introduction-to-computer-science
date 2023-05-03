import React from 'react';
import { Container, Row, Col } from 'react-bootstrap';

const HomePage = () => {
  return (
    <Container fluid>
      <Row className="justify-content-center align-items-center vh-100">
        <Col md={6} className="text-center">
          <h1>Welcome to Cyber Brain</h1>
          <p>A second brain to organize your life.</p>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
