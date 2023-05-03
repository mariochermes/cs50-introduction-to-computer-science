import React from 'react';
import { Container, Row, Col, Button } from 'react-bootstrap';

const HomePage = () => {
  return (
    <Container fluid>
      <Row className="justify-content-center align-items-center" style={{ height: '100vh' }}>
        <Col md={8} className="text-center">
          <h1>Welcome to Cyber Brain!</h1>
          <p>A second brain to help you organize your life.</p>
          <Button variant="primary">Get Started</Button>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
