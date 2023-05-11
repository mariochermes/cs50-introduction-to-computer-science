import { Button, Container, Image, Nav, Navbar, Offcanvas } from 'react-bootstrap';
import { publicUrl } from '../index';

export default function PageButton({ pageName, iconUrl }) {
    return (
    <Button className="tasks-page-button align-items-center d-flex flex-column h-100 justify-content-center pt-2 rounded-2 w-100" style={{ minHeight:'120px' }}>
        <Image src={`${publicUrl}/${pageName}.png`} alt={`{pageName} icon`} width={60} height={60} />
        <h5 className="mt-auto">Archives</h5>
      </Button>
    );
}