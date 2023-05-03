import React from 'react';
import { Container, Row, Col } from 'react-bootstrap';

const HomePage = () => {
  return (
    <Container fluid className="w-75 align">
      <Row className="text-center">
        <Col className="text-center">
          <h1>Welcome to Cyber Brain</h1>
          <p>A second brain to organize your life.</p>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
