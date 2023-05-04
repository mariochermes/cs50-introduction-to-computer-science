import React from 'react';
import { Link } from 'react-router-dom';
import { Button, Container, Image } from 'react-bootstrap';
import logo from '/logo.png';
import sunIcon from '../../public/sun-icon.png';
import graphicElement from './images/graphic-element.png';

const HomePage = () => {
  return (
    <Container className="d-flex flex-column align-items-center justify-content-center h-100">
      <div className="d-flex justify-content-between w-100 mb-4">
        <Image src={sunIcon} className="align-self-center" width={30} height={30} />
        <Image src={logo} className="align-self-center" />
      </div>
      <h1 className="text-center mb-5">Cyberbrain</h1>
      <Image src={graphicElement} className="mb-5" />
      <div className="d-flex justify-content-center w-100">
        <Button variant="primary" className="m-2">
          <Link to="/tasks" className="text-white text-decoration-none">
            <i className="bi bi-card-checklist"></i>
            <span className="ms-2">Tasks</span>
          </Link>
        </Button>
        <Button variant="primary" className="m-2">
          <Link to="/areas" className="text-white text-decoration-none">
            <i className="bi bi-columns"></i>
            <span className="ms-2">Areas</span>
          </Link>
        </Button>
        <Button variant="primary" className="m-2">
          <Link to="/resources" className="text-white text-decoration-none">
            <i className="bi bi-folder2-open"></i>
            <span className="ms-2">Resources</span>
          </Link>
        </Button>
        <Button variant="primary" className="m-2">
          <Link to="/archives" className="text-white text-decoration-none">
            <i className="bi bi-archive"></i>
            <span className="ms-2">Archives</span>
          </Link>
        </Button>
      </div>
    </Container>
  );
};

export default HomePage;
