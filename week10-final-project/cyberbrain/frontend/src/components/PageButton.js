import { Button, Container, Image, Nav, Navbar, Offcanvas } from 'react-bootstrap';
import { publicUrl } from '../index';
import '../styles/page-button.css';

export default function PageButton({ pageName }) {
    return (
    <Button className="tasks-page-button align-items-center d-flex flex-column h-100 justify-content-center pt-2 rounded-2 w-100">
        <Image src={`${publicUrl}/${pageName}-icon.png`} alt={`${pageName} icon`} width={60} height={60} />
        <h5 className="mt-auto">{pageName.charAt(0).toUpperCase() + pageName.slice(1)}</h5>
      </Button>
    );
}