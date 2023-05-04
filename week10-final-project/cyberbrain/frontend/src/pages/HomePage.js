import React from 'react';
import { Button, Col, Container, Image, Row } from 'react-bootstrap';
import { publicUrl } from '../index';

const HomePage = () => {
  return (
    <Container className="d-flex flex-column align-items-center justify-content-center h-100 min-vh-100" maxWidth={1200}>
      <Row className="justify-content-end w-100">
        <Col xs="auto">
        <Image src={`${publicUrl}/sunIconDark.png`} className="align-self-end" width={30} height={30} />
        </Col>
      </Row>
      <Row className="align-items-center justify-content-center text-center w-100">
        <Col xs="auto">
          <Image fluid src={`${publicUrl}/cyberbrainLogo.png`} width={350} height={350} />
          <h1 className="my-4">Cyberbrain</h1>
          <svg className="cyber-element" width="100%" height="100%">
            <line x1="50%" y1="0" x2="50%" y2="50%" stroke="white" strokeWidth="2" strokeLinecap="round" />
            <circle cx="50%" cy="50%" r="3" fill="white" />
            <line x1="50%" y1="50%" x2="25%" y2="75%" stroke="white" strokeWidth="2" strokeLinecap="round" />
            <circle cx="25%" cy="75%" r="3" fill="white" />
            <line x1="50%" y1="50%" x2="75%" y2="75%" stroke="white" strokeWidth="2" strokeLinecap="round" />
            <circle cx="75%" cy="75%" r="3" fill="white" />
            <line x1="50%" y1="50%" x2="0" y2="100%" stroke="white" strokeWidth="2" strokeLinecap="round" />
            <circle cx="0" cy="100%" r="3" fill="white" />
          </svg>
        </Col>
      </Row>
      <Row className="w-100">
        <Col xs="auto" className="text-center w-100">
          <Row className="justify-content-evenly">
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/cyberbrainLogo.png`} alt="Tasks Icon" width={64} height={64} />
              <h5 className="my-3">Tasks</h5>
            </Col>
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/cyberbrainLogo.png`} alt="Areas Icon" width={64} height={64} />
              <h5 className="my-3">Areas</h5>
            </Col>
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/cyberbrainLogo.png`} alt="Resources Icon" width={64} height={64} />
              <h5 className="my-3">Resources</h5>
            </Col>
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/cyberbrainLogo.png`} alt="Archives Icon" width={64} height={64} />
              <h5 className="my-3">Archives</h5>
            </Col>
          </Row>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
