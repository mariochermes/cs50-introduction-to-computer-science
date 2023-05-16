import { useState } from 'react';
import { Button, Container, CloseButton, Image, Nav, Navbar, Offcanvas } from 'react-bootstrap';
import { publicUrl } from '../index';
import '../styles/navigation-bar.css';

export default function NavigationBar() {
  const [darkMode, setDarkMode] = useState(true);
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  return (
    <>
      <Navbar className="px-3" expand={false} sticky="top">
        <Navbar.Toggle aria-controls="offcanvasNavbar"/>
        <Navbar.Offcanvas
          id="offcanvasNavbar"
          aria-labelledby="offcanvasNavbarLabel"
          placement="start"
        >
          <Container fluid className="d-flex flex-column h-100">
            <CloseButton aria-label="Close" className=""/>
            <Offcanvas.Header>
              <Offcanvas.Title className="flex-grow-1" id="offcanvasNavbarLabel">
                <Nav>
                  <Nav.Link className="align-items-center d-flex justify-content-between" href="#home">
                    CyberBrain
                    <Image src={`${publicUrl}/cyberbrain-icon.png`} width={42}></Image>
                  </Nav.Link>
                </Nav>
              </Offcanvas.Title>
            </Offcanvas.Header>
            <Offcanvas.Body className="d-flex flex-column justify-content-center">
              <Nav>
                <Nav.Link className="d-flex justify-content-between" href="#tasks">
                  Tasks
                  <Image src={`${publicUrl}/tasks-icon.png`} width={28}></Image>
                </Nav.Link>
                <Nav.Link className="d-flex justify-content-between" href="#areas">
                  Areas
                  <Image src={`${publicUrl}/areas-icon.png`} width={28}></Image>
                </Nav.Link>
                <Nav.Link className="d-flex justify-content-between" href="#resources">
                  Resources
                  <Image src={`${publicUrl}/resources-icon.png`} width={28}></Image>
                </Nav.Link>
                <Nav.Link className="d-flex justify-content-between" href="#archives">
                  Archives
                  <Image src={`${publicUrl}/archives-icon.png`} width={28}></Image>
                </Nav.Link>
              </Nav>
            </Offcanvas.Body>
            <Container className="mt-auto p-3">
              <Nav>
                {isLoggedIn ? (
                  <Nav.Link className="d-flex justify-content-between" href="#Logout">
                    Logout
                    <Image src={`${publicUrl}/logout-icon.png`} width={28}></Image>
                  </Nav.Link>
                ) : (
                  <>
                    <Nav.Link className="d-flex justify-content-between" href="#login">
                      Login
                      <Image src={`${publicUrl}/login-icon.png`} width={28}></Image>
                    </Nav.Link>
                    <Nav.Link className="d-flex justify-content-between" href="#sign-up">
                      Sign Up
                      <Image src={`${publicUrl}/sign-up-icon.png`} width={28}></Image>
                    </Nav.Link>
                  </>
                )}
              </Nav>
            </Container>
          </Container>
        </Navbar.Offcanvas>
        <Button
          className="toggle-mode-button"
          onClick={() => setDarkMode(!darkMode)}
          variant="outline-transparent"
        >
          <img src={`${publicUrl}/sun-icon-dark.png`} alt="sun icon" className="align-self-end" width={28} height={28} />
        </Button>
      </Navbar>
    </>
  );
}
