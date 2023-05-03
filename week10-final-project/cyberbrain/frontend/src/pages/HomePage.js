import React from 'react';
import { Container, Row, Col } from 'react-bootstrap';

const HomePage = () => {
  return (
    <Container fluid className="d-flex align-items-center justify-content-center h-100">
      <Row className="text-center">
        <Col>
          <h1>Welcome to Cyber Brain</h1>
          <p>A second brain to organize your life.</p>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
