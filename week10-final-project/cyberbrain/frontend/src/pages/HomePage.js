import React from 'react';
import { Button, Col, Container, Image, Row } from 'react-bootstrap';
import { publicUrl } from '../index';
import CyberLine from '../components/CyberLine'

const HomePage = () => {
  return (
    <Container className="align-items-center d-flex flex-column justify-content-between h-100 min-vh-100 py-5" maxWidth={1200}>
      <Row className="justify-content-end w-100">
        <Col xs="auto">
        <Image src={`${publicUrl}/sun-icon-dark.png`} className="align-self-end" width={30} height={30} />
        </Col>
      </Row>
      <Row className="align-items-center justify-content-center text-center w-100">
        <Col xs="auto">
          <Image fluid src={`${publicUrl}/cyberbrain-logo-512.png`} width={350} height={350} />
          <h1 className="my-3">CyberBrain</h1>
        </Col>
        <CyberLine start={{ x: 100, y: 100 }} end={{ x: 200, y: 200 }} />
      </Row>
      <Row className="pb-5 w-100">
        <Col xs="auto" className="text-center w-100">
          <Row className="justify-content-evenly">
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/tasks-icon.png`} alt="Tasks Icon" width={64} height={64} />
              <h5 className="my-3">Tasks</h5>
            </Col>
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/areas-icon.png`} alt="Areas Icon" width={64} height={64} />
              <h5 className="my-3">Areas</h5>
            </Col>
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/resources-icon.png`} alt="Resources Icon" width={64} height={64} />
              <h5 className="my-3">Resources</h5>
            </Col>
            <Col xs="auto" className="text-center">
              <img src={`${publicUrl}/archives-icon.png`} alt="Archives Icon" width={64} height={64} />
              <h5 className="my-3">Archives</h5>
            </Col>
          </Row>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
