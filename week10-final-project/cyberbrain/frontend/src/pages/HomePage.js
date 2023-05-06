import React from 'react';
import { Button, Col, Container, Image, Row } from 'react-bootstrap';
import { publicUrl } from '../index';
import { SteppedLineTo } from 'react-lineto';

const HomePage = () => {
  return (
    <Container className="align-items-center d-flex flex-column justify-content-between h-100 min-vh-100 py-5" maxWidth={1200}>
      <Row className="justify-content-end w-100">
        <Col xs="auto">
          <img src={`${publicUrl}/sun-icon-dark.png`} alt="sun icon" className="align-self-end" width={28} height={28} />
        </Col>
      </Row>
      <Row className="align-items-center justify-content-center text-center w-100">
        <Col xs="auto">
          <img src={`${publicUrl}/cyberbrain-logo-512.png`} alt="CyberBrain logo" width={350}/>
          <h1 className="page-title">CyberBrain<span class="blink">.</span></h1>
        </Col>
      </Row>
      {/* <SteppedLineTo borderColor="#B7B7B7" from="page-title" to="tasks-page-button" orientation="v" fromAnchor="bottom" toAnchor="top" /> */}
      <Row className="w-100 h-100">
        <Col className="text-center w-100" xs={12} sm={8} lg={4}>
          <Row className="justify-content-evenly">
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <button className="tasks-page-button align-items-center d-flex flex-column h-100 justify-content-center pt-2 rounded-2 w-100" style={{ minHeight:'120px' }}>
                <img src={`${publicUrl}/tasks-icon.png`} alt="Tasks Icon" width={60} height={60} />
                <h5 className="mt-auto">Tasks</h5>
              </button>

            </Col>
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <button className="align-items-center d-flex flex-column h-100 justify-content-center pt-2 rounded-2 w-100">
                <img src={`${publicUrl}/areas-icon.png`} alt="Areas Icon" width={60} height={60} />
                <h5 className="mt-auto">Areas</h5>
              </button>
            </Col>
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <button className="align-items-center d-flex flex-column h-100 justify-content-center pt-2 rounded-2 w-100">
                <img src={`${publicUrl}/resources-icon.png`} alt="Resources Icon" width={60} height={60} />
                <h5 className="mt-auto">Resources</h5>
              </button>
            </Col>
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <button className="align-items-center d-flex flex-column h-100 justify-content-center pt-2 rounded-2 w-100">
                <img src={`${publicUrl}/archives-icon.png`} alt="Archives Icon" width={60} height={60} />
                <h5 className="mt-auto">Archives</h5>
              </button>
            </Col>
          </Row>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
