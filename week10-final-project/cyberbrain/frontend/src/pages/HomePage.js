import React from 'react';
import { Container, Row, Col } from 'react-bootstrap';

const HomePage = () => {
  return (
    <Container fluid className="h-100 w-75">
      <Row className="align-items-center d-flex justify-content-center" style={{ height: "100vh" }}>
        <Col className="text-center">
          <img src="" alt="CyberBrain Logo"/>
          <h1>Welcome to Cyber Brain</h1>
          <p>A second brain to organize your life.</p>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
